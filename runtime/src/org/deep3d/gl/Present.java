package org.deep3d.gl;

import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL13.GL_TEXTURE0;
import static org.lwjgl.opengl.GL13.glActiveTexture;
import static org.lwjgl.opengl.GL20.*;

/**
 * Puts the rendered frame on the window: scales it into the destination
 * rectangle with "sharp bilinear" filtering (square pixels stay square and
 * even at non-integer scales, with only their edges blended).
 */
final class Present {

    private static final String VSH =
            "#version 130\n"
            + "uniform vec4 uDst;\n"          // x, y, w, h in clip space
            + "out vec2 vUV;\n"
            + "void main() {\n"
            + "  vec2 c = vec2(float(gl_VertexID & 1), float(gl_VertexID >> 1));\n"
            + "  vUV = c;\n"
            + "  gl_Position = vec4(uDst.xy + c * uDst.zw, 0.0, 1.0);\n"
            + "}\n";

    private static final String FSH =
            "#version 130\n"
            + "uniform sampler2D uTex;\n"
            + "uniform vec2 uSrcSize;\n"      // frame size in pixels
            + "uniform vec2 uScale;\n"        // window pixels per frame pixel
            + "in vec2 vUV;\n"
            + "out vec4 fragColor;\n"
            + "void main() {\n"
            + "  vec2 texel = vUV * uSrcSize;\n"
            + "  vec2 base = floor(texel);\n"
            + "  vec2 d = fract(texel) - 0.5;\n"
            + "  vec2 range = 0.5 - 0.5 / max(uScale, vec2(1.0));\n"
            + "  vec2 f = (d - clamp(d, -range, range)) * max(uScale, vec2(1.0)) + 0.5;\n"
            + "  vec3 c = texture(uTex, (base + f) / uSrcSize).rgb;\n"
            + "  fragColor = vec4(c, 1.0);\n"
            + "}\n";

    private int program;
    private int uDst;
    private int uSrcSize;
    private int uScale;
    private int uTex;

    void init() {
        program = GL2D.buildProgram(VSH, FSH);
        uDst = glGetUniformLocation(program, "uDst");
        uSrcSize = glGetUniformLocation(program, "uSrcSize");
        uScale = glGetUniformLocation(program, "uScale");
        uTex = glGetUniformLocation(program, "uTex");
    }

    /**
     * Draws texture {@code tex} (srcW x srcH, bottom-up like the window) into
     * the window rectangle dst* (window pixels, top-left origin) of a fbW x fbH
     * window.
     */
    void draw(int tex, int srcW, int srcH, int dstX, int dstY, int dstW, int dstH,
              int fbW, int fbH) {
        glViewport(0, 0, fbW, fbH);
        glDisable(GL_SCISSOR_TEST);
        glDisable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
        for (int i = 0; i < 8; i++) {
            glDisableVertexAttribArray(i);   // the quad comes from gl_VertexID
        }
        glUseProgram(program);
        float x = dstX * 2f / fbW - 1f;
        float y = 1f - (dstY + dstH) * 2f / fbH;
        glUniform4f(uDst, x, y, dstW * 2f / fbW, dstH * 2f / fbH);
        glUniform2f(uSrcSize, srcW, srcH);
        glUniform2f(uScale, (float) dstW / srcW, (float) dstH / srcH);
        glUniform1i(uTex, 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, org.lwjgl.opengl.GL12.GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, org.lwjgl.opengl.GL12.GL_CLAMP_TO_EDGE);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glBindTexture(GL_TEXTURE_2D, 0);
        glUseProgram(0);
    }
}
