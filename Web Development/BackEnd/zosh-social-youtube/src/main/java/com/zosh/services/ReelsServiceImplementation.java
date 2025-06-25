package com.zosh.services;

import java.time.LocalDateTime;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.zosh.exceptions.UserException;
import com.zosh.models.Reels;
import com.zosh.models.User;
import com.zosh.repository.ReelsRepository;

@Service
public class ReelsServiceImplementation implements ReelsService{

	@Autowired
	ReelsRepository reelsRepository;
	
	@Autowired
	UserService userService;
	
	@Override
	public Reels createReels(Reels reels, User user) {
		
		Reels newReel=new Reels();
		
		newReel.setTitle(reels.getTitle());
		newReel.setUser(user);
		newReel.setVideo(reels.getVideo());
		newReel.setCreatedAt(LocalDateTime.now());
		
		return reelsRepository.save(newReel);
		
	}

	@Override
	public List<Reels> findReelsByUserId(Integer userId) throws UserException {
		
		userService.findUserById(userId);

		return reelsRepository.findReelsByUserId(userId);
		
	}

	@Override
	public List<Reels> findAllReels() {
		
		return reelsRepository.findAll();
	
	}

}
