package com.google.gwt.sample.docs.client;

import com.google.gwt.sample.docs.basics.DelayedLogic;
import com.google.gwt.sample.docs.shared.FieldVerifier;

import java.util.Date;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.core.client.GWT;
import com.google.gwt.dom.client.Style.Unit;
import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.event.dom.client.KeyCodes;
import com.google.gwt.event.dom.client.KeyUpEvent;
import com.google.gwt.event.dom.client.KeyUpHandler;
import com.google.gwt.user.client.History;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.Button;
import com.google.gwt.user.client.ui.DialogBox;
import com.google.gwt.user.client.ui.DockLayoutPanel;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.LayoutPanel;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.SplitLayoutPanel;
import com.google.gwt.user.client.ui.TabPanel;
import com.google.gwt.user.client.ui.TextBox;
import com.google.gwt.user.client.ui.VerticalPanel;
import com.google.gwt.user.client.ui.Widget;
import com.google.gwt.event.logical.shared.SelectionEvent;
import com.google.gwt.event.logical.shared.SelectionHandler;
import com.google.gwt.event.logical.shared.ValueChangeEvent;
import com.google.gwt.event.logical.shared.ValueChangeHandler;
import com.google.gwt.i18n.client.NumberFormat;


/**
 * Entry point classes define <code>onModuleLoad()</code>.
 */
public class GwtDocs implements EntryPoint {
	/**
	 * The message displayed to the user when the server cannot be reached or
	 * returns an error.
	 */
	private static final String SERVER_ERROR = "An error occurred while "
			+ "attempting to contact the server. Please check your network " + "connection and try again.";

	/**
	 * Create a remote service proxy to talk to the server-side Greeting service.
	 */
	private final GreetingServiceAsync greetingService = GWT.create(GreetingService.class);
	
	private final CustomServiceAsync customService = GWT.create(CustomService.class);
	
	TabPanel tabPanel;
	
	/**
	 * This is the entry point method.
	 */
	public void onModuleLoad() {
    
		final Button sendButton = new Button("Send");
		final Button customButton = new Button("Query");
		final Button clearButton = new Button("Clear");
		final TextBox nameField = new TextBox();
		nameField.setText("GWT User");
		final Label errorLabel = new Label();
		final Label customLabel = new Label();

		// We can add style names to widgets
		sendButton.addStyleName("sendButton");

		// Add the nameField and sendButton to the RootPanel
		// Use RootPanel.get() to get the entire body element
		RootPanel.get("nameFieldContainer").add(nameField);
		RootPanel.get("sendButtonContainer").add(sendButton);
		RootPanel.get("errorLabelContainer").add(errorLabel);
		RootPanel.get("customLabelContainer").add(customLabel);
		RootPanel.get("customButtonContainer").add(customButton);
		RootPanel.get("clearButtonContainer").add(clearButton);
		
		customButton.addClickHandler(new ClickHandler() {
			public void onClick(ClickEvent event) {
				customService.customMethod("Custom Message", new AsyncCallback<String>() {
					public void onFailure(Throwable caught) {
						// Show the RPC error message to the user

					}
					public void onSuccess(String result) {
						customLabel.setText(result);
					}
				});
			}
		});

		clearButton.addClickHandler(new ClickHandler() {
			public void onClick(ClickEvent event) {
				customLabel.setText("");
			}
		});

		// Focus the cursor on the name field when the app loads
		nameField.setFocus(true);
		nameField.selectAll();

		// Create the popup dialog box
		final DialogBox dialogBox = new DialogBox();
		dialogBox.setText("Remote Procedure Call");
		dialogBox.setAnimationEnabled(true);
		final Button closeButton = new Button("Close");
		// We can set the id of a widget by accessing its Element
		closeButton.getElement().setId("closeButton");
		final Label textToServerLabel = new Label();
		final HTML serverResponseLabel = new HTML();
		VerticalPanel dialogVPanel = new VerticalPanel();
		dialogVPanel.addStyleName("dialogVPanel");
		dialogVPanel.add(new HTML("<b>Sending name to the server:</b>"));
		dialogVPanel.add(textToServerLabel);
		dialogVPanel.add(new HTML("<br><b>Server replies:</b>"));
		dialogVPanel.add(serverResponseLabel);
		dialogVPanel.setHorizontalAlignment(VerticalPanel.ALIGN_RIGHT);
		dialogVPanel.add(closeButton);
		dialogBox.setWidget(dialogVPanel);

		// Add a handler to close the DialogBox
		closeButton.addClickHandler(new ClickHandler() {
			public void onClick(ClickEvent event) {
				dialogBox.hide();
				sendButton.setEnabled(true);
				sendButton.setFocus(true);
			}
		});

		// Create a handler for the sendButton and nameField
		class MyHandler implements ClickHandler, KeyUpHandler {
			/**
			 * Fired when the user clicks on the sendButton.
			 */
			public void onClick(ClickEvent event) {
				sendNameToServer();
			}

			/**
			 * Fired when the user types in the nameField.
			 */
			public void onKeyUp(KeyUpEvent event) {
				if (event.getNativeKeyCode() == KeyCodes.KEY_ENTER) {
					sendNameToServer();
				}
			}

			/**
			 * Send the name from the nameField to the server and wait for a response.
			 */
			private void sendNameToServer() {
				// First, we validate the input.
				errorLabel.setText("");
				String textToServer = nameField.getText();
				if (!FieldVerifier.isValidName(textToServer)) {
					errorLabel.setText("Please enter at least four characters");
					return;
				}

				// Then, we send the input to the server.
				sendButton.setEnabled(false);
				textToServerLabel.setText(textToServer);
				serverResponseLabel.setText("");
				greetingService.greetServer(textToServer, new AsyncCallback<String>() {
					public void onFailure(Throwable caught) {
						// Show the RPC error message to the user
						dialogBox.setText("Remote Procedure Call - Failure");
						serverResponseLabel.addStyleName("serverResponseLabelError");
						serverResponseLabel.setHTML(SERVER_ERROR);
						dialogBox.center();
						closeButton.setFocus(true);
					}

					public void onSuccess(String result) {
						dialogBox.setText("Remote Procedure Call");
						serverResponseLabel.removeStyleName("serverResponseLabelError");
						serverResponseLabel.setHTML(result);
						dialogBox.center();
						closeButton.setFocus(true);
					}
				});
			}
		}

		// Add a handler to send the name to the server
		MyHandler handler = new MyHandler();
		sendButton.addClickHandler(handler);
		nameField.addKeyUpHandler(handler);
		
		tabPanel = new TabPanel();
		tabPanel.add(new HTML("<h1>Page 0 Content: Llamas</h1>"), " Page 0 ");
	    tabPanel.add(new HTML("<h1>Page 1 Content: Alpacas</h1>"), " Page 1 ");
	    tabPanel.add(new HTML("<h1>Page 2 Content: Camels</h1>"), " Page 2 ");
	    
	    tabPanel.addSelectionHandler(new SelectionHandler<Integer>() {
	    	public void onSelection(SelectionEvent<Integer> event) {
	    		History.newItem("page" + event.getSelectedItem());
	    	}
	    });
	    
	    History.addValueChangeHandler(new ValueChangeHandler<String>() {
	    	public void onValueChange(ValueChangeEvent<String> event) {
	    		String historyToken = event.getValue();
	    		try {
	    			if (historyToken.substring(0,  4).equals("page")) {
	    				String tabIndexToken = historyToken.substring(4,  5);
	    				int tabIndex = Integer.parseInt(tabIndexToken);
	    				tabPanel.selectTab(tabIndex);
	    			} else {
	    				tabPanel.selectTab(0);
	    			}
	    		} catch (IndexOutOfBoundsException e) {
	    			tabPanel.selectTab(0);
	    		}
	    	} 
	    });

	    tabPanel.selectTab(0);
	    RootPanel.get("tabContainer").add(tabPanel);
	    
	    final Label formattingLabel = new Label();
	    RootPanel.get("formattingContainer").add(formattingLabel);
	    
	    NumberFormat fmt = NumberFormat.getDecimalFormat();
	    double value = 12345.6789;
	    String formatted = fmt.format(value);
	    // Prints 1,2345.6789 in the default locale
	    GWT.log("Formatted string is" + formatted, null);
	    
	    formattingLabel.setText(formatted);
	    
	    Date today = new Date();
	    // prints Tue Dec 18 12:01:26 GMT-500 2007 in the default locale.
	    GWT.log(today.toString(), null);
	    
	    new DelayedLogic().startWork();
	    
//	    WorkingWithJSON.alert("jnsi alert!");

	}
}
