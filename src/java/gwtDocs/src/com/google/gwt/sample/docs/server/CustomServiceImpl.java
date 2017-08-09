package com.google.gwt.sample.docs.server;

import com.google.gwt.sample.docs.client.CustomService;
import com.google.gwt.user.server.rpc.RemoteServiceServlet;

public class CustomServiceImpl extends RemoteServiceServlet implements CustomService {
	public String customMethod(String s) {
		return s;
	}
}
