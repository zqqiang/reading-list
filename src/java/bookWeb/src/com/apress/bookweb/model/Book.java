package com.apress.bookweb.model;

import java.util.List;

public class Book {
	private Long id;
	private Long categoryId;
	private String bookTitle;
	private List<Author> authors;

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	
	public Long getCategoryId() {
		return categoryId;
	}

	public void setCategoryId(Long categoryId) {
		this.categoryId = categoryId;
	}

	public String getBookTitle() {
		return bookTitle;
	}

	public void setBookTitle(String bookTitle) {
		this.bookTitle = bookTitle;
	}

	public List<Author> getAuthors() {
		return authors;
	}

	public void setAuthors(List<Author> authors) {
		this.authors = authors;
	}


	public String toString() {
		return "Book - Id: " + id + ", Book Title: " + bookTitle;
	}

}
