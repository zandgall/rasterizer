import re
import clipping
import vertex as vt

class face:
    def __init__(self):
        self.a_v = -1
        self.a_vt = -1
        self.a_vn = -1
        
        self.b_v = -1
        self.b_vt = -1
        self.b_vn = -1
        
        self.c_v = -1
        self.c_vt = -1
        self.c_vn = -1
        
class object:
    def __init__(self):
        self.vertices = []
        self.uvs = []
        self.normals = []
        self.faces = []
        
def load_obj(filepath):
    out = object()
    
    line_number = 0
    with open(filepath, "r") as file:
        while line := file.readline():
            line_number += 1
            if line.startswith('v '):
                nums = list(map(float, re.findall(r'-?\d+\.\d*', line)))
                if len(nums)<3:
                    print("Error: vertex at line #" + str(line_number) + " doesn't have 3 or more coordinates")
                out.vertices.append(vt.vec4(nums[0], nums[1], nums[2], 1))
            elif line.startswith('vt '):
                nums = list(map(float, re.findall(r'-?\d+\.\d*', line)))
                if len(nums)<2:
                    print("Error: vertex texture at line #" + str(line_number) + " doesn't have 2 or more coordinates")
                out.uvs.append(vt.vec2(nums[0], nums[1]))
            elif line.startswith('vn '):
                nums = list(map(float, re.findall(r'-?\d+\.\d*', line)))
                if len(nums)<3:
                    print("Error: vertex normal at line #" + str(line_number) + " doesn't have 3 or more coordinates")
                out.normals.append(vt.vec3(nums[0], nums[1], nums[2]))
            elif line.startswith('f '):
                nums = list(map(int, re.findall(r'\d+', line)))
                f = len(out.faces)
                out.faces.append(face())
                if len(out.uvs) + len(out.normals) == 0:
                    out.faces[f].a_v = nums[0]-1
                    out.faces[f].b_v = nums[1]-1
                    out.faces[f].c_v = nums[2]-1
                elif len(out.normals) == 0:
                    out.faces[f].a_v = nums[0]-1
                    out.faces[f].a_vt = nums[1]-1
                    out.faces[f].b_v = nums[2]-1
                    out.faces[f].b_vt = nums[3]-1
                    out.faces[f].c_v = nums[4]-1
                    out.faces[f].c_vt = nums[5]-1
                elif len(out.uvs) == 0:
                    out.faces[f].a_v = nums[0]-1
                    out.faces[f].a_vn = nums[1]-1
                    out.faces[f].b_v = nums[2]-1
                    out.faces[f].b_vn = nums[3]-1
                    out.faces[f].c_v = nums[4]-1
                    out.faces[f].c_vn = nums[5]-1
                else:
                    out.faces[f].a_v = nums[0]-1
                    out.faces[f].a_vt = nums[1]-1
                    out.faces[f].a_vn = nums[2]-1
                    out.faces[f].b_v = nums[3]-1
                    out.faces[f].b_vt = nums[4]-1
                    out.faces[f].b_vn = nums[5]-1
                    out.faces[f].c_v = nums[6]-1
                    out.faces[f].c_vt = nums[7]-1
                    out.faces[f].c_vn = nums[8]-1
    return out

def draw_object(obj, vs, v_uni, fs, f_uni, tri_draw_func):
    verts = [vt.vertex(), vt.vertex(), vt.vertex()]
    
    verts[0].vec4s = []
    verts[0].vec3s = [vt.vec3(0, 0, 0)]
    verts[0].vec2s = [vt.vec2(0, 0)]
    
    verts[1].vec4s = []
    verts[1].vec3s = [vt.vec3(0, 0, 0)]
    verts[1].vec2s = [vt.vec2(0, 0)]
    
    verts[2].vec4s = []
    verts[2].vec3s = [vt.vec3(0, 0, 0)]
    verts[2].vec2s = [vt.vec2(0, 0)]
    
    for i in range(len(obj.faces)):
        verts[0].pos = obj.vertices[obj.faces[i].a_v]
        verts[1].pos = obj.vertices[obj.faces[i].b_v]
        verts[2].pos = obj.vertices[obj.faces[i].c_v]
        
        if obj.faces[i].a_vt == -1:
            verts[0].vec2s[0] = vt.vec2(0,0)
            verts[1].vec2s[0] = vt.vec2(0,0)
            verts[2].vec2s[0] = vt.vec2(0,0)
        else:
            verts[0].vec2s[0] = obj.uvs[obj.faces[i].a_vt]
            verts[1].vec2s[0] = obj.uvs[obj.faces[i].b_vt]
            verts[2].vec2s[0] = obj.uvs[obj.faces[i].c_vt]
            
        if obj.faces[i].a_vn == -1:
            verts[0].vec3s[0] = vt.vec3(0, 0,0)
            verts[1].vec3s[0] = vt.vec3(0, 0,0)
            verts[2].vec3s[0] = vt.vec3(0, 0,0)
        else:
            verts[0].vec3s[0] = obj.normals[obj.faces[i].a_vn]
            verts[1].vec3s[0] = obj.normals[obj.faces[i].b_vn]
            verts[2].vec3s[0] = obj.normals[obj.faces[i].c_vn]
        
        clipping.draw(verts, vs, v_uni, fs, f_uni, tri_draw_func)
