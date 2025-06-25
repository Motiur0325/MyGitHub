import * as React from "react";
import Box from "@mui/material/Box";
import Button from "@mui/material/Button";
import Modal from "@mui/material/Modal";
import { useDispatch, useSelector } from "react-redux";
import { useFormik } from "formik";
import {
  Avatar,
  Backdrop,
  CircularProgress,
  Divider,
  IconButton,
} from "@mui/material";
import ImageIcon from "@mui/icons-material/Image";
import VideocamIcon from "@mui/icons-material/Videocam";
// import CloseIcon from "@mui/icons-material/Close";
import { useState } from "react";
import { uploadToCloudinary } from "../Utilities/uploadToCloudinary";
import { createPostAction } from "../Redux/Auth/post.action";
import { blue, grey, red } from "@mui/material/colors";
import CloseIcon from "@mui/icons-material/Close";

const style = {
  position: "absolute",
  top: "50%",
  left: "50%",
  transform: "translate(-50%, -50%)",
  width: 600,
  bgcolor: "background.paper",
  boxShadow: 24,
  p: 3,
  overFlow: "scroll-y",
  outline: "none",
  borderRadius: 3,
};

export default function PostModal({ open, handleClose }) {
  const [selectedImage, setSelectedImage] = useState(null);
  const [selectedVideo, setSelectedVideo] = useState();
  const [isLoading, setisLoading] = useState(false);
  const auth = useSelector((store) => store.auth);
  const dispatch = useDispatch();

  const handleSelectImage = async (event) => {
    setisLoading(true);
    const imageUrl = await uploadToCloudinary(event.target.files[0], "image");
    setSelectedImage(imageUrl);
    setisLoading(false);
    formik.setFieldValue("image", imageUrl);
  };

  const handleSelectVideo = async (event) => {
    setisLoading(true);
    const videoUrl = await uploadToCloudinary(event.target.files[0], "video");
    setSelectedVideo(videoUrl);
    setisLoading(false);
    formik.setFieldValue("video", videoUrl);
  };

  const formik = useFormik({
    initialValues: {
      caption: "",
      image: "",
      video: "",
    },
    onSubmit: (values) => {
      console.log("values", values);
      dispatch(createPostAction(values));
    },
  });
  return (
    <div>
      <Modal
        open={open}
        onClose={handleClose}
        aria-labelledby="modal-modal-title"
        aria-describedby="modal-modal-description"
      >
        <Box sx={style}>
          <form onSubmit={formik.handleSubmit}>
            <div className="p-3 pr-6 pb-6">
              <div className="flex justify-between items-center mb-4">
                <div className="flex items-center space-x-3">
                  <Avatar sx={{ bgcolor: red[500] }}>
                    {auth.user.firstName.charAt(0)}
                  </Avatar>
                  <div>
                    <p className="font-bold text-lg">
                      {auth.user?.firstName + " " + auth.user?.lastName}
                    </p>
                    <p className="text-sm">{auth.user?.email}</p>
                  </div>
                </div>
                <IconButton color="error" onClick={handleClose}>
                  <CloseIcon />
                </IconButton>
              </div>
              <textarea
                className="outline-none w-full mt-5 p-2 bg-transparent border border-[#3b4054] rounded-sm"
                name="caption"
                placeholder="Write Caption..."
                value={formik.values.caption}
                onChange={formik.handleChange}
                rows="4"
              />
              <div className="flex space-x-5 mt-5 items-center">
                <div>
                  <input
                    type="file"
                    accept="image/*"
                    onChange={handleSelectImage}
                    style={{ display: "none" }}
                    id="image-input"
                  />
                  <label htmlFor="image-input">
                    <IconButton color="primary" component="span">
                      <ImageIcon />
                      <span className=" ml-1 text-sm text-black">Image</span>
                    </IconButton>
                  </label>
                </div>
                <div>
                  <input
                    type="file"
                    accept="video/*"
                    onChange={handleSelectVideo}
                    style={{ display: "none" }}
                    id="video-input"
                  />
                  <label htmlFor="video-input">
                    <IconButton color="primary" component="span">
                      <VideocamIcon />
                      <span className=" ml-1 text-sm text-black">Video</span>
                    </IconButton>
                  </label>
                </div>
              </div>
              {selectedImage && (
                <div>
                  <img className="h-[10rem]" src={selectedImage} alt="" />
                </div>
              )}
              {selectedVideo && (
                <div>
                  <video className="h-[10rem]" src={selectedVideo} alt="" />
                </div>
              )}
              <div className="flex w-full justify-end">
                <Button
                  type="submit"
                  variant="contained"
                  size="large"
                  sx={{ borderRadius: "1.5rem" }}
                >
                  Post
                </Button>
              </div>
            </div>
          </form>
          <Backdrop
            sx={(theme) => ({ color: "#fff", zIndex: theme.zIndex.drawer + 1 })}
            open={isLoading}
            onClick={handleClose}
          >
            <CircularProgress color="inherit" />
          </Backdrop>
        </Box>
      </Modal>
    </div>
  );
}
