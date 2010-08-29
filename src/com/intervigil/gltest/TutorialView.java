package com.intervigil.gltest;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;

public class TutorialView extends GLSurfaceView {

	private static final String CLASS_NAME = "TutorialView";
	
	private TutorialRenderer mRenderer;
	
	public TutorialView(Context context) {
		super(context);
		mRenderer = new TutorialRenderer();
		setRenderer(mRenderer);
	}
	
	@Override
    public void onPause() {
    	Log.i(CLASS_NAME, "onPause()");
    	super.onPause();
    	nativePause();
    }
    
    @Override
    public void onResume() {
    	Log.i(CLASS_NAME, "onResume()");
    	super.onResume();
    	nativeResume();
    }

	@Override
    public boolean onTrackballEvent(MotionEvent event) {
    	return false;
    }
    
    @Override
    public boolean onTouchEvent(MotionEvent event) {
    	return false;
    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
    	nativeHandleKeyEvent(keyCode);
    	return true;
    }
    
    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
    	nativeHandleKeyEvent(keyCode);
    	return true;
    }
    
    private static native void nativePause();
    private static native void nativeResume();
    private static native void nativeHandleKeyEvent(int keyCode);
}
