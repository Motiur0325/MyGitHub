package com.zosh.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RestController;

import com.zosh.models.Reels;
import com.zosh.models.User;
import com.zosh.services.ReelsService;
import com.zosh.services.UserService;

@RestController
public class ReelsController {

	@Autowired
	UserService userService;
	
	@Autowired 
	ReelsService reelsService;
	
	@PostMapping("/api/reels")
	public Reels createReelsHandler(@RequestBody Reels reels,@RequestHeader("Authorization") String jwt) {
		
		User user=userService.findUserByToken(jwt);
		
		return reelsService.createReels(reels,user);
		
	}
	
	@GetMapping("/api/reels/user/{userId}")
	public List<Reels> findReelsByUserIdHandler(@PathVariable Integer userId) throws Exception{
		
		return reelsService.findReelsByUserId(userId);
		
	}
	
	@GetMapping("/api/reels")
	public List<Reels> findAllReelsHandler(){
		
		return reelsService.findAllReels();
		
	}
	
}
