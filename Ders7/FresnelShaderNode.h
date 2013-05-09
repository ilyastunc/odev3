//
//  NormalShaderNode.h
//  Ders 7
//
//  Created by Gurel Erceis on 4/1/13.
//  Copyright (c) 2013 Yogurt3D. All rights reserved.
//

#ifndef FresnelShaderNode_h
#define FresnelShaderNode_h
#include <windows.h>
#include "Camera.h"
#include "ShadedGeometry.h"

class FresnelShaderNode: public ShadedGeometry{
public:
    FresnelShaderNode(char *filename):
    ShadedGeometry(filename,
                   "fresnel_vert_shader.vert",
                   "fresnel_frag_shader.frag")
    {
        generateBuffers();    
    }
    ~FresnelShaderNode(){
        
    }
    void draw(SceneNode *camera){

        glUseProgram(programId);
        
        //glm::mat4 MVPmatrix = ((Camera*)camera)->projectionMatrix * camera->getInverseModelMatrix() * getModelMatrix();

		glm::mat4 MVPmatrix = camera->getInverseModelMatrix() * getModelMatrix();

        
        glUniformMatrix4fv(UniformMVP, 1, GL_FALSE, &MVPmatrix[0][0]);


        
        
        // vertex bufferi bagla
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glVertexAttribPointer(AttributePosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        // normal buffer i bagla
        glBindBuffer(GL_ARRAY_BUFFER, normalBufferID);
		glVertexAttribPointer(AttributeNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        // indiceleri bagla
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBufferID);
        
        // Attributelari enable et
        glEnableVertexAttribArray(AttributePosition);
        glEnableVertexAttribArray(AttributeNormal);
        
        // ciz
        glDrawElements(GL_TRIANGLES, int(faceArray.size()), GL_UNSIGNED_INT, BUFFER_OFFSET(0));
        
        
        // baglantilari kopar
        glDisableVertexAttribArray(AttributeNormal);
        glDisableVertexAttribArray(AttributePosition);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        
        glUseProgram(0);
    }
private:
    GLuint UniformMVP;
    GLuint AttributePosition,AttributeNormal;
	//GLuint color1, color2, cosx;
    
    
    void generateBuffers(){
        
        UniformMVP = glGetUniformLocation(programId, "MVP");
        printf("UniformMVP: %d\n",UniformMVP);
        
        AttributePosition = glGetAttribLocation(programId, "Position");
        printf("Position Attribute: %d\n", AttributePosition);
        
        AttributeNormal = glGetAttribLocation(programId, "Normal");
        printf("Normal Attribute: %d\n", AttributeNormal);
        
		/*color1 = glGetUniformLocation(programId, "color1");
		color2 = glGetUniformLocation(programId, "color2");*/

    }
};

#endif
