package com.zosh.services;

import java.util.List;

import com.zosh.exceptions.UserException;
import com.zosh.models.Post;
import com.zosh.models.User;

public interface PostService {

	Post createnewPost(Post post,Integer userId) throws UserException;
	
	String deletePost(Integer postId,Integer userId)throws UserException;
	
	List<Post> findPostByUserId(Integer userId);
	
	Post findPostById(Integer postId)throws UserException;
	
	List<Post> findAllPosts();
	
	User savePost(Integer postId,Integer userId) throws UserException;
	
	Post likePost(Integer postId,Integer userId) throws UserException;
	
}
