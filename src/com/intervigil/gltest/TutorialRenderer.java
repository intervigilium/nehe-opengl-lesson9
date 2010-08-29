package com.intervigil.gltest;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;

public class TutorialRenderer implements GLSurfaceView.Renderer {

	@Override
	public void onDrawFrame(GL10 gl) {
		nativeRender();
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		nativeResize(width, height);
	}

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		nativeInit();
	}

	private static native void nativeInit(); 
	private static native void nativeResize(int w, int h);
	private static native void nativeRender();
}
