package com.google.gwt.sample.docs.client;

import com.google.gwt.user.client.rpc.RemoteService;
import com.google.gwt.user.client.rpc.RemoteServiceRelativePath;

@RemoteServiceRelativePath("customService")
public interface CustomService extends RemoteService {
	public String customMethod(String s);
}
