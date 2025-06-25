import { Grid } from "@mui/material";
import React, { useEffect } from "react";
import Sidebar from "../../components/Sidebar";
import { Route, Routes, useLocation } from "react-router-dom";
import Reels from "../../components/Reels";
import CreateReels from "../../components/CreateReels";
import Profile from "../../components/Profile";
import Middlepart from "../../components/Middlepart";
import HomeRight from "../../components/HomeRight";
import { useDispatch, useSelector } from "react-redux";
import { getProfileAction } from "../../Redux/Auth/auth.action";
// import { Store } from "../../Redux/Store";

const Home = () => {
  const location = useLocation();
  const dispatch = useDispatch();
  const jwt = localStorage.getItem("jwt");
  const { auth } = useSelector((Store) => Store);

  useEffect(() => {
    dispatch(getProfileAction(jwt));
  }, []);

  return (
    <div>
      <Grid container spacing={0}>
        <Grid item xs={0} lg={3}>
          <div className="sticky top-0 ml-20">
            <Sidebar />
          </div>
        </Grid>
        <Grid
          item
          className="px-5 flex justify-center"
          xs={12}
          lg={location.pathname === "/" ? 6 : 9}
        >
          <Routes>
            <Route path="/" element={<Middlepart />} />
            <Route path="/reels" element={<Reels />} />
            <Route path="/create-reels" element={<CreateReels />} />
            <Route path="/profile/:id" element={<Profile />} />
          </Routes>
        </Grid>
        {location.pathname === "/" && (
          <Grid item lg={3} className="relative">
            <div className="sticky top-0 w-full">
              <HomeRight />
            </div>
          </Grid>
        )}
      </Grid>
    </div>
  );
};

export default Home;
