uniform vec4 color;
uniform sampler2D texture;
varying vec3 v_position;
varying vec3 v_normal; 
varying vec3 v_position2;
varying vec2 v_uv;
void main() {

    vec2 coords = vec2((gl_FragCoord.x/1280)*2-1.0, (gl_FragCoord.y/800)*2 -1.0) ;
    float intensity = length(coords);
    gl_FragColor = vec4(0.0f, 0.0f, 0.0f, intensity);

}