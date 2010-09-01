package com.intervigil.gltest;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.opengl.GLSurfaceView;

public class TutorialRenderer implements GLSurfaceView.Renderer {

	private Context context;
	
	public TutorialRenderer(Context context) {
		this.context = context;
	}
	
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
		String apkFilePath = null;
		ApplicationInfo appInfo = null;
		PackageManager packMgmr =  context.getPackageManager();
		try {
		    appInfo = packMgmr.getApplicationInfo(context.getPackageName(), 0);
	    } catch (NameNotFoundException e) {
		    e.printStackTrace();
		    throw new RuntimeException("Unable to locate assets, aborting...");
	    }
		apkFilePath = appInfo.sourceDir;
		nativeInit(apkFilePath);
	}

	private static native void nativeInit(String apkPath); 
	private static native void nativeResize(int w, int h);
	private static native void nativeRender();
}
