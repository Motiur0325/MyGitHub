package com.zosh.response;

public class AuthResponse {

	private String token;
	private String Message;
	
	public AuthResponse() {
		
	}
	
	public AuthResponse(String token, String message) {
		super();
		this.token = token;
		Message = message;
	}

	public String getToken() {
		return token;
	}

	public void setToken(String token) {
		this.token = token;
	}

	public String getMessage() {
		return Message;
	}

	public void setMessage(String message) {
		Message = message;
	}
	
}
