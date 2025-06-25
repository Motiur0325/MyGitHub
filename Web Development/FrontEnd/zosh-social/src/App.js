import { Route, Routes } from "react-router-dom";
import React, { useEffect } from "react";
import "./App.css";
import Authentication from "./pages/Authentication/Authentication";
import Home from "./pages/Authentication/Home";
import Message from "./components/Message";
// import { Store } from "./Redux/Store";
import { useDispatch, useSelector } from "react-redux";
import { getProfileAction } from "./Redux/Auth/auth.action";

function App() {
  const { auth } = useSelector((Store) => Store);
  const dispatch = useDispatch();
  const jwt = localStorage.getItem("jwt");

  useEffect(() => {
    dispatch(getProfileAction(jwt));
  }, [jwt]);
  return (
    <div>
      <Routes>
        <Route path="/*" element={auth.user ? <Home /> : <Authentication />} />
        <Route path="/message" element={<Message />} />
      </Routes>
    </div>
  );
}

export default App;
