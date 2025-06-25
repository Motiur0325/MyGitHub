package com.zosh.services;

import java.util.List;

import com.zosh.exceptions.UserException;
import com.zosh.models.User;

public interface UserService {
	
	public User registerUser(User user);
	
	public List<User> showUser();
	
	public User findUserById(Integer userId) throws UserException;
	
	public User findUserByEmail(String email);
	
	public User followUser(String jwt,Integer followId) throws UserException;
	
	public User updateUser(String jwt,User user) throws UserException;
	
	public List<User> searchUser(String query);
	
	public User findUserByToken(String jwt);
	
}
