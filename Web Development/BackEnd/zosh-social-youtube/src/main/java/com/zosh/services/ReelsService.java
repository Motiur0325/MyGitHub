package com.zosh.services;

import java.util.List;

import com.zosh.exceptions.UserException;
import com.zosh.models.Reels;
import com.zosh.models.User;

public interface ReelsService {
	
	public Reels createReels(Reels reels,User user);
	
	public List<Reels> findReelsByUserId(Integer userId) throws UserException;
	
	public List<Reels> findAllReels();
	
}
