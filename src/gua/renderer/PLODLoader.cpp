/******************************************************************************
 * guacamole - delicious VR                                                   *
 *                                                                            *
 * Copyright: (c) 2011-2013 Bauhaus-Universität Weimar                        *
 * Contact:   felix.lauer@uni-weimar.de / simon.schneegans@uni-weimar.de      *
 *                                                                            *
 * This program is free software: you can redistribute it and/or modify it    *
 * under the terms of the GNU General Public License as published by the Free *
 * Software Foundation, either version 3 of the License, or (at your option)  *
 * any later version.                                                         *
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   *
 * for more details.                                                          *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program. If not, see <http://www.gnu.org/licenses/>.             *
 *                                                                            *
 ******************************************************************************/

// class header
#include <gua/renderer/PLODLoader.hpp>
#include <pbr/ren/lod_point_cloud.h>
#include <pbr/ren/model_database.h>
#include <gua/renderer/PLODRessource.hpp>

// guacamole headers
#include <gua/utils/TextFile.hpp>
#include <gua/utils/Logger.hpp>
#include <gua/utils/string_utils.hpp>
#include <gua/scenegraph/PLODNode.hpp>
#include <gua/scenegraph/TransformNode.hpp>
#include <gua/renderer/Material.hpp>
#include <gua/renderer/MaterialLoader.hpp>
#include <gua/renderer/GeometryLoader.hpp>
#include <gua/renderer/PLODRessource.hpp>
#include <gua/databases/MaterialDatabase.hpp>
#include <gua/databases/GeometryDatabase.hpp>
#include <gua/databases/ShadingModelDatabase.hpp>

#include <iostream>

namespace gua {

unsigned PLODLoader::model_counter_ = 0;

  /////////////////////////////////////////////////////////////////////////////

 PLODLoader::PLODLoader()
     : node_counter_(0) {}

  /////////////////////////////////////////////////////////////////////////////

std::shared_ptr<Node> PLODLoader::load(std::string const& file_name,
                                      unsigned flags) {
   
   std::string model_name("type=file&file=" + file_name);
   
   auto node(std::make_shared<PLODNode>(model_name));
   node->set_filename(model_name);
   node->set_material("");

   pbr::ren::ModelDatabase* database = pbr::ren::ModelDatabase::GetInstance();
  
   // load point cloud
   pbr::model_t model_id = database->AddModel(file_name, model_name);
   const pbr::ren::LodPointCloud* point_cloud = database->GetModel(model_id);

   GeometryDatabase::instance()->add(model_name, std::make_shared<PLODRessource>(point_cloud));
   
   ++model_counter_;
   
   return node;

}

  /////////////////////////////////////////////////////////////////////////////

std::vector<PLODRessource*> const PLODLoader::load_from_buffer(char const* buffer_name,
                                                             unsigned buffer_size,
                                                             bool build_kd_tree) {

  return std::vector<PLODRessource*>();
}

bool PLODLoader::is_supported(std::string const& file_name) const {
  auto point_pos(file_name.find_last_of("."));

  return file_name.substr(point_pos + 1) == "kdn";
}

}