import React from "react";

const UserReelsCard = () => {
  return (
    <div className="px-2 w-[15rem]">
      <video
        controls
        className="w-full h-full mb-8"
        src="https://videos.pexels.com/video-files/29868624/12823722_360_640_30fps.mp4"
      />
    </div>
  );
};

export default UserReelsCard;
