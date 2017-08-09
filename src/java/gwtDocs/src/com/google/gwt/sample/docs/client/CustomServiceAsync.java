package com.google.gwt.sample.docs.client;

import com.google.gwt.user.client.rpc.AsyncCallback;

public interface CustomServiceAsync {
	public void customMethod(String s, AsyncCallback<String> callback);
}
