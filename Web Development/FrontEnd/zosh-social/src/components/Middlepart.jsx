import { Avatar, Card, IconButton } from "@mui/material";
import React, { useEffect, useState } from "react";
import AddIcon from "@mui/icons-material/Add";
import StoryCircle from "./StoryCircle";
import ImageIcon from "@mui/icons-material/Image";
import VideocamIcon from "@mui/icons-material/Videocam";
import ArticleIcon from "@mui/icons-material/Article";
import PostCard from "./PostCard";
import PostModal from "./PostModal";
import { useDispatch, useSelector } from "react-redux";
import { getAllPostAction } from "../Redux/Auth/post.action";
import { red } from "@mui/material/colors";

const story = [1, 1, 1, 1, 1];

const Middlepart = (item) => {
  const [open, setOpen] = useState(false);
  const handleClose = () => setOpen(false);
  const dispatch = useDispatch();
  const post = useSelector((Store) => Store.post);
  const auth = useSelector((store) => store.auth);

  const handleOpenCreatePostModal = () => {
    setOpen(true);
    console.log("handle open post modal...");
  };

  useEffect(() => {
    dispatch(getAllPostAction());
  }, [post.newComment]);

  return (
    <div className="px-20">
      <section className="p-3 mt-6 flex item-center rounded-b-md">
        <div className="flex flex-col items-center mr-8 cursor-pointer">
          <Avatar sx={{ width: "5.5rem", height: "5.5rem" }}>
            <AddIcon sx={{ fontSize: "3rem" }} />
          </Avatar>
          <p>New</p>
        </div>
        {story.map((item) => (
          <StoryCircle />
        ))}
      </section>
      <Card className="p-5 mt-5">
        <div className="flex justify-between">
          <Avatar sx={{ bgcolor: red[300], width: "3rem", height: "3rem" }}>
            {auth.user.firstName.charAt(0)}
          </Avatar>
          <input
            readOnly
            onClick={handleOpenCreatePostModal}
            className="outline-none w-[90%] bg-slate-100 rounded-full px-5 bg-transparent border-[#3b4054] border"
            type="text"
            value="Create Post Here"
          />
        </div>
        <div className="flex justify-center space-x-9 mt-5">
          <div className="flex items-center">
            <IconButton color="primary" onClick={handleOpenCreatePostModal}>
              <ImageIcon />
              <span className=" ml-1 text-sm text-black">Image</span>
            </IconButton>
          </div>
          <div className="flex items-center">
            <IconButton onClick={handleOpenCreatePostModal}>
              <VideocamIcon color="primary" />
              <span className=" ml-1 text-sm text-black">Video</span>
            </IconButton>
          </div>
          <div className="flex items-center">
            <IconButton color="primary" onClick={handleOpenCreatePostModal}>
              <ArticleIcon />
            </IconButton>
            <span>Write Article</span>
          </div>
        </div>
      </Card>
      <div className="mt-5 space-y-5">
        {post.posts.map((item) => (
          <PostCard item={item} />
        ))}
      </div>
      <div>
        <PostModal open={open} handleClose={handleClose} />
      </div>
    </div>
  );
};

export default Middlepart;
