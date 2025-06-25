import { Avatar, Box, Button, Tabs, Tab, Card } from "@mui/material";
import React, { useState } from "react";
import PostCard from "./PostCard";
import UserReelsCard from "./UserReelsCard";
import ProfileModal from "./ProfileModal";
import { useSelector } from "react-redux";
// import { useParams } from "react-router-dom";

const tabs = [
  { value: "post", name: "Post" },
  { value: "reels", name: "Reels" },
  { value: "saved", name: "Saved" },
  { value: "repost", name: "Repost" },
];

const reels = [1, 1, 1, 1, 1];

const Profile = () => {
  // const { id } = useParams();
  const [open, setOpen] = useState(false);
  const handleOpenProfileModal = () => setOpen(true);
  const handleClose = () => setOpen(false);
  const [value, setValue] = useState("post");
  const auth = useSelector((store) => store.auth);
  const post = useSelector((store) => store.post);
  const userPosts = useSelector((state) =>
    state.post.posts.filter((post) => post.user.id === state.auth.user.id)
  );

  console.log("auth", auth);
  console.log("posts", post);
  console.log("UserPost", userPosts);
  const handleChange = (event, newValue) => {
    setValue(newValue);
  };
  return (
    <Card className="py-10 w-[70%]">
      <div className="rounded-md">
        <div className="h-[15rem]">
          <img
            alt=""
            className="w-full h-full rounded-t-md"
            src="https://cdn.pixabay.com/photo/2018/08/14/13/23/ocean-3605547_640.jpg"
          />
        </div>
        <div className="px-5 flex justify-between items-start mt-5 h-[5rem]">
          <Avatar
            className="transform -translate-y-24"
            sx={{ width: "10rem", height: "10rem" }}
            src="https://cdn.pixabay.com/photo/2016/10/20/18/35/earth-1756274_640.jpg"
          />
          {true ? (
            <Button
              onClick={handleOpenProfileModal}
              sx={{ borderRadius: "20px" }}
              variant="outlined"
            >
              Edit Profile
            </Button>
          ) : (
            <Button sx={{ borderRadius: "20px" }} variant="outlined">
              Follow
            </Button>
          )}
        </div>
        <div className="p-5">
          <div>
            <h1 className="py-1 font-bold text-xl">
              {auth.user.firstName + " " + auth.user.lastName}
            </h1>
            <p>{auth.user?.email}</p>
          </div>
          <div className="flex gap-5 items-center py-3">
            <span>41post</span>
            <span>35 Followers</span>
            <span>10 Followings</span>
          </div>
          <div>
            <p>Hello Visitor! Welcome to my profile.</p>
          </div>
        </div>
        <section>
          <Box sx={{ width: "100%", borderBottom: 1, borderColor: "divider" }}>
            <Tabs
              value={value}
              onChange={handleChange}
              aria-label="wrapped label tabs example"
            >
              {tabs.map((item) => (
                <Tab value={item.value} label={item.name} />
              ))}
            </Tabs>
          </Box>
          <div className="flex justify-center">
            {value === "post" ? (
              <Card className="space-y-5 w-[70%] my-10">
                {post.posts.length > 0 ? (
                  post.posts.map((item) =>
                    item.user.id === auth.user.id ? (
                      <div
                        key={item.id}
                        className="border rounded-md border-slate-100"
                      >
                        <PostCard item={item} />
                      </div>
                    ) : null
                  )
                ) : (
                  <div>You have no posts yet ...</div>
                )}
              </Card>
            ) : value === "reels" ? (
              <div className="flex flex-wrap justify-center mx-20 my-20 gap-2">
                {reels.map((item) => (
                  <UserReelsCard />
                ))}
              </div>
            ) : value === "saved" ? (
              <Card className="space-y-5 w-[70%] my-10">
                {auth.savedPost.map((item) => (
                  <div className="border rounded-md border-slate-100">
                    <PostCard />
                  </div>
                ))}
              </Card>
            ) : (
              <div>Repost</div>
            )}
          </div>
        </section>
      </div>
      <section>
        <ProfileModal open={open} handleClose={handleClose} />
      </section>
    </Card>
  );
};

export default Profile;
