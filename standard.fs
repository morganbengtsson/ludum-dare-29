#ifdef GL_ES
precision mediump float;
precision mediump int;
#endif
uniform vec4 color;
uniform sampler2D texture;
uniform vec3 camera_position;
varying vec3 v_position;
varying vec3 v_normal; 
varying vec3 v_position2;
varying vec2 v_uv;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
vec3 ambient = vec3(0.3, 0.3, 0.3);
float d = (v_position.z + 100.0)/5000.0;

vec3 light = normalize(camera_position - v_position2);
float intensity = max(dot(v_normal,light), 0.0) * 0.1;        

float rand1 = rand(v_uv) - 0.5;
float rand2 = rand(v_uv + 2.0) - 0.5;

vec3 indirect = texture2D(texture, v_uv).rgb;
float alpha = texture2D(texture, v_uv).a;

float fog_cord = (gl_FragCoord.z / gl_FragCoord.w) / 1000.0;
float fog_density = 40.0;
float fog = fog_cord * fog_density;
vec3 fog_color = vec3(0.0, 0.1, 0.2);

vec3 frag_color = mix(fog_color, indirect, clamp(1.0 - fog, 0.0, 1.0));


gl_FragColor = vec4(frag_color*(1.0 - (rand(gl_FragCoord.xy)*0.1)), alpha);

//gl_FragColor = vec4(indirect, 1.0);

//gl_FragColor = vec4(color.xyz, 1.0);

//gl_FragColor = vec4(v_uv.xy, 1.0, 1.0);
//gl_FragColor = vec4(texture2D(texture, v_uv).rgb, 1.0);
//gl_FragColor = vec4(v_normal, 1.0); 
}
