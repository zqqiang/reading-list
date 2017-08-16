package com.google.gwt.sample.docs.basics;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.ui.CheckBox;
import com.google.gwt.user.client.ui.Composite;
import com.google.gwt.user.client.ui.TextBox;
import com.google.gwt.user.client.ui.VerticalPanel;

public class OptionalTextBox extends Composite implements ClickHandler {

	private TextBox textBox = new TextBox();
	private CheckBox checkBox = new CheckBox();
	
	public OptionalTextBox(String caption) {
		VerticalPanel panel = new VerticalPanel();
		panel.add(checkBox);
		panel.add(textBox);
		
		checkBox.setText(caption);
		checkBox.addClickHandler(this);
		
		initWidget(panel);
		
		setStyleName("example-OptionalCheckBox");
	}
	
	@Override
	public void onClick(ClickEvent event) {
		Object sender = event.getSource();
		if(sender == checkBox) {

		}
	}

	public void setCaption(String caption) {
		checkBox.setText(caption);
	}
	
	public String getCaption() {
		return checkBox.getText();
	}
}
