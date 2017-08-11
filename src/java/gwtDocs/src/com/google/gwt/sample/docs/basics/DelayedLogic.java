package com.google.gwt.sample.docs.basics;

import com.google.gwt.core.client.GWT;
import com.google.gwt.sample.docs.client.GreetingService;
import com.google.gwt.sample.docs.client.GreetingServiceAsync;
import com.google.gwt.user.client.Timer;
import com.google.gwt.user.client.rpc.AsyncCallback;

public class DelayedLogic {
	// A keeper of the timer instance in case we need to cancel it
	private Timer timeoutTimer = null;

	// An indicator when the computation should quit
	private boolean abortFlag = false;

	static final int TIMEOUT = 30; // 30 second timeout

	private final GreetingServiceAsync greetingService = GWT.create(GreetingService.class);

	public void startWork() {

		// ...

		// Check to make sure the timer isn't already running.
		if (timeoutTimer != null) {
			GWT.log("Command is already running!");
			return;
		}

		// Create a timer to abort if the RPC takes too long
		timeoutTimer = new Timer() {
			public void run() {
				GWT.log("Timeout expired.");
				timeoutTimer = null;
				abortFlag = true;
			}
		};

		// (re)Initialize the abort flag and start the timer.
		abortFlag = false;
		timeoutTimer.schedule(TIMEOUT * 1000); // timeout is in milliseconds

		// Kick off an RPC
		greetingService.greetServer("Timer Message", new AsyncCallback<String>() {

			public void onFailure(Throwable caught) {
				GWT.log("RPC Failed:" + caught);
				cancelTimer();
			}

			public void onSuccess(String result) {
				cancelTimer();
				if (abortFlag) {
					// Timeout already occurred. discard result
					return;
				}
				GWT.log("RPC returned: " + (String) result);
			}
		});
	}

	// Stop the timeout timer if it is running
	private void cancelTimer() {
		if (timeoutTimer != null) {
			timeoutTimer.cancel();
			timeoutTimer = null;
		}
	}
}
