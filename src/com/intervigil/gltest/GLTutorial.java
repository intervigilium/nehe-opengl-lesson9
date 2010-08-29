package com.intervigil.gltest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class GLTutorial extends Activity {
	
	private static final String NDK_LIB = "gltutorial";
	private static final String APP_NAME = "GLTutorial";

	private TutorialView mGLSurfaceView;
	
	static {
		System.loadLibrary(NDK_LIB);
	}
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
    	Log.i(APP_NAME, "onCreate()");
        super.onCreate(savedInstanceState);
        
        mGLSurfaceView = new TutorialView(GLTutorial.this);
        setContentView(mGLSurfaceView);
    }
    
    @Override
    protected void onDestroy() {
    	Log.i(APP_NAME, "onDestroy()");
    	super.onDestroy();
    }
    
    @Override
    protected void onPause() {
    	Log.i(APP_NAME, "onPause()");
    	super.onPause();
    	mGLSurfaceView.onPause();
    }
    
    @Override
    protected void onResume() {
    	Log.i(APP_NAME, "onResume()");
    	super.onResume();
    	mGLSurfaceView.onResume();
    }
}