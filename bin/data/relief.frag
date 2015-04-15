varying vec3 light;
varying vec3 halfvector;
varying vec4 diffuse;
varying vec4 ambient;
varying vec4 globalambient;
                                      
varying float distance;
                                      
uniform sampler2D textureMap;
uniform sampler2D normalMap;
uniform sampler2D diffuseMap;
                                  
uniform float alpha;
                                      
void main() {
                
        // texture lookup
    float x = gl_TexCoord[0].s;
    float y = gl_TexCoord[0].t;
    // extract the normal from the normal map
    vec3 norm = normalize(texture2D(normalMap, vec2(x, y)).rgb * 2. - 1.);
    // ambient component is always present
    vec4 col = globalambient;
    // compute dot product between normal and normalized light
    float normDotLight = max(dot(norm, normalize(light)), 0.);
                
    // if dot product > 0
    //if(normDotLight > 0.) {
                    
        // calculate attenuation
        float attenuation = 1. / (gl_LightSource[0].constantAttenuation + gl_LightSource[0].linearAttenuation * distance + gl_LightSource[0].quadraticAttenuation * distance * distance);
                    
        // add diffuse component
        col += attenuation * (diffuse * normDotLight + ambient);
        // normalize half vector
        vec3 HV = normalize(halfvector);
        // compute dot product
        float normDotHV = max(dot(norm, HV), 0.);
        // add specular component
        col += attenuation * gl_FrontMaterial.specular * gl_LightSource[0].specular * pow( normDotHV, gl_FrontMaterial.shininess );
                
    //}
                
    // set color
    vec4 bump = col * vec4(texture2D(textureMap, vec2(x, y)).rgb, 1.0);
    vec4 diff = vec4(texture2D(diffuseMap, vec2(x, y)).rgb, 1.0);
                
    // additive blending
    gl_FragColor = mix(  vec4((gl_Color).rgb, alpha), vec4((bump + diff).rgb, alpha), 0.8);          
            
}