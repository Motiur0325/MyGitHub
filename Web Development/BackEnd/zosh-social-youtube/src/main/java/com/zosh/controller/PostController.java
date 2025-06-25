package com.zosh.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RestController;

import com.zosh.models.Post;
import com.zosh.models.User;
import com.zosh.response.ApiResponse;
import com.zosh.services.PostService;
import com.zosh.services.UserService;

@RestController
public class PostController {

	@Autowired
	PostService postService;
	
	@Autowired
	UserService userService;
	
	@PostMapping("/api/posts")
	public ResponseEntity<Post> createPost(@RequestHeader("Authorization")String jwt,@RequestBody Post post) throws Exception{
		
		Integer userId=userService.findUserByToken(jwt).getId();
		Post newPost=postService.createnewPost(post,userId);
		return new ResponseEntity<>(newPost,HttpStatus.ACCEPTED);
	}
	
	@DeleteMapping("/api/posts/{postId}")
	public ResponseEntity<ApiResponse> deletePost(@PathVariable Integer postId,@RequestHeader("Authorization")String jwt) throws Exception{
		
		Integer userId=userService.findUserByToken(jwt).getId();
		
		String message=postService.deletePost(postId,userId);
		
		ApiResponse response=new ApiResponse(message,true);
		
		return new ResponseEntity<>(response,HttpStatus.OK);
		
	}
	
	@GetMapping("/api/posts/{postId}")
	public ResponseEntity<Post> findPostByIdHandler(@PathVariable Integer postId)throws Exception{
		
		Post post=postService.findPostById(postId);
		return new ResponseEntity<>(post,HttpStatus.ACCEPTED);
		
	}
	
	
	@GetMapping("/api/posts/user/{userId}")
	public ResponseEntity<List<Post>> findPostByUserId(@PathVariable Integer userId) {
		
		List<Post> post=postService.findPostByUserId(userId);
		return new ResponseEntity<>(post,HttpStatus.OK);
		
	}
	
	@GetMapping("/api/posts")
	public ResponseEntity<List<Post>> findAllPost(){
		
		List<Post> posts=postService.findAllPosts();
		return new ResponseEntity<>(posts,HttpStatus.OK);
		
	}
	
	@PutMapping("/api/posts/save/{postId}")
	public ResponseEntity<User> savePost(@PathVariable Integer postId,@RequestHeader("Authorization")String jwt) throws Exception{
		
		Integer userId=userService.findUserByToken(jwt).getId();
		User user=postService.savePost(postId,userId);
		return new ResponseEntity<>(user,HttpStatus.ACCEPTED);
		
	}
	
	@PutMapping("/api/posts/like/{postId}")
	public ResponseEntity<Post> likePost(@PathVariable Integer postId,@RequestHeader("Authorization")String jwt)throws Exception{
		
		Integer userId=userService.findUserByToken(jwt).getId();
		Post post=postService.likePost(postId,userId);
		return new ResponseEntity<>(post,HttpStatus.ACCEPTED);
		
	}
	
}
