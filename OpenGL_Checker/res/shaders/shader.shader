#shader vertex
#version 460 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 auv;

out vec3 pos;
out vec2 uv;
uniform mat4 screen;
void main() {
	gl_Position = screen * vec4(aPos, 1);
	pos = (screen * vec4(aPos, 1)).xyz;
	uv = auv;
}

#shader fragment
#version 460 core

in vec3 pos;
in vec2 uv;
out vec4 glColor;
uniform sampler2D text;
void main() {
	// glColor = vec4(mod(pos.x, 1), mod(pos.y, 1), mod(pos.z, 1), 1);
	glColor = vec4(uv, 1, 1);
	//glColor = vec4(1, 0, 0, 1);
	// glColor = texture2D(text, uv);
	//glColor.z = pos.z;
}