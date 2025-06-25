package com.zosh.services;

import java.util.List;

import com.zosh.exceptions.UserException;
import com.zosh.models.Story;
import com.zosh.models.User;

public interface StoryService {

	public Story createStory(Story story,User user) throws UserException;
	
	public List<Story> findStoryByUserId(Integer id);
	
}
