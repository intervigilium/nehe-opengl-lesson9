package com.intervigil.gltest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class GLTutorial extends Activity {
	
	private static final String NDK_LIB = "gltutorial";
	private static final String CLASS_NAME = "GLTutorial";

	private TutorialView mGLSurfaceView;
	
	static {
		System.loadLibrary(NDK_LIB);
	}
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
    	Log.i(CLASS_NAME, "onCreate()");
        super.onCreate(savedInstanceState);
        
        mGLSurfaceView = new TutorialView(GLTutorial.this);
        setContentView(mGLSurfaceView);
    }
    
    @Override
    protected void onDestroy() {
    	Log.i(CLASS_NAME, "onDestroy()");
    	super.onDestroy();
    	mGLSurfaceView.onDestroy();
    }
    
    @Override
    protected void onPause() {
    	Log.i(CLASS_NAME, "onPause()");
    	super.onPause();
    	mGLSurfaceView.onPause();
    }
    
    @Override
    protected void onResume() {
    	Log.i(CLASS_NAME, "onResume()");
    	super.onResume();
    	mGLSurfaceView.onResume();
    }
}