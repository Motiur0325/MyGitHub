import React from "react";
import Login from "./Login";
import { Card, Grid } from "@mui/material";
import { Route, Routes } from "react-router-dom";
import Register from "./Register";

const Authentication = () => {
  return (
    <div>
      <Grid container>
        <Grid className="h-screen overflow-hidden" item xs={7}>
          <img
            alt="change"
            className="h-full w-full"
            src="https://cdn.pixabay.com/photo/2018/11/29/21/51/social-media-3846597_1280.png"
          ></img>
        </Grid>
        <Grid item xs={5}>
          <div className="px-20 flex flex-col justify-center h-full">
            <Card className="card p-20">
              <div className="flex flex-col items-center mb-5 space-y-1">
                <h1 className="logo text-center">Zosh Social</h1>
                <p className="text-center text-sm w-[70%]">
                  Connecting Lives, Sharing stories, Your Social world, Your Way
                </p>
              </div>
              <Routes>
                <Route path="/" element={<Login />} />
                <Route path="/login" element={<Login />} />
                <Route path="/register" element={<Register />}></Route>
              </Routes>
            </Card>
          </div>
        </Grid>
      </Grid>
    </div>
  );
};

export default Authentication;
