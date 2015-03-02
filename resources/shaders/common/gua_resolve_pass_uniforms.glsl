uniform int     gua_background_mode;
uniform vec3    gua_background_color;
uniform uvec2   gua_background_texture;

uniform int     gua_environment_lighting_mode;
uniform uvec2   gua_environment_lighting_spheremap;
uniform uvec2   gua_environment_lighting_cubemap;
uniform vec3    gua_environment_lighting_color;

uniform bool    gua_ssao_enable;
uniform float   gua_ssao_radius;
uniform float   gua_ssao_intensity;
uniform float   gua_ssao_falloff;
uniform uvec2   gua_noise_tex;

uniform bool    gua_enable_fog = false;
uniform float   gua_fog_start  = 1.0;
uniform float   gua_fog_end    = 100.0;
 
uniform float   gua_tone_mapping_exposure = 1.0;
uniform int     gua_tone_mapping_operator = 0;