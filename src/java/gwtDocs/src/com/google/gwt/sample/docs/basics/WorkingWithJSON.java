package com.google.gwt.sample.docs.basics;

import com.google.gwt.core.client.JavaScriptObject;
import com.google.gwt.core.client.JsonUtils;

public class WorkingWithJSON {
	public static <T extends JavaScriptObject> T parseJson(String jsonStr) {
		return JsonUtils.safeEval(jsonStr);
	}
}
