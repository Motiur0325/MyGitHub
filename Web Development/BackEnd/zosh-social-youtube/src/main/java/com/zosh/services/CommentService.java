package com.zosh.services;

import com.zosh.exceptions.UserException;
import com.zosh.models.Comment;

public interface CommentService {

	public Comment createComment(Comment comment,Integer postId,Integer userId) throws UserException;
	
	public Comment findCommentById(Integer commentId) throws UserException;
	
	public Comment likeComment(Integer commentId,Integer userId) throws UserException;
	
	
}
