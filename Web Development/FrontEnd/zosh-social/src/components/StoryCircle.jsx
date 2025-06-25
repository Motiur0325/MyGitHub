import { Avatar } from "@mui/material";
import React from "react";
import AddIcon from "@mui/icons-material/Add";

const StoryCircle = () => {
  return (
    <div>
      <div className="flex flex-col items-center mr-8 cursor-pointer">
        <Avatar
          sx={{ width: "5.5rem", height: "5.5rem" }}
          src="https://media.istockphoto.com/id/1161878589/photo/bueatiful-tea-plantation-on-mountain.jpg?s=2048x2048&w=is&k=20&c=S3Zow4qlkOvWySLGoM4MCERydeHBxRbQUjnSKH2vbNY="
        >
          <AddIcon sx={{ fontSize: "3rem" }} />
        </Avatar>
        <p>Story</p>
      </div>
    </div>
  );
};

export default StoryCircle;
