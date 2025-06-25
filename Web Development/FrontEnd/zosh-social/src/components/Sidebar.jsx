import React from "react";
import { navigationMenu } from "./SidebarNav";
import { Avatar, Card, Divider } from "@mui/material";
import Button from "@mui/material/Button";
import Menu from "@mui/material/Menu";
import MenuItem from "@mui/material/MenuItem";
import MoreVertIcon from "@mui/icons-material/MoreVert";
import { useSelector } from "react-redux";
import { useNavigate } from "react-router-dom";

const Sidebar = () => {
  const [anchorEl, setAnchorEl] = React.useState(null);
  const open = Boolean(anchorEl);
  const { auth } = useSelector((Store) => Store);
  const navigate = useNavigate();

  const handleNavigate = (item) => {
    if (item.title === "Profile") {
      navigate(`/profile/${auth.user?.id}`);
    } else {
      navigate(item.path);
    }
  };
  const handleClick = (event) => {
    setAnchorEl(event.currentTarget);
  };
  const handleClose = () => {
    setAnchorEl(null);
  };

  return (
    <Card className="card h-screen flex flex-col justify-between py-5">
      <div className="space-y-8 pl-5">
        <div className="">
          <span className="logo font-bold text-xl">Zosh Social</span>
        </div>
        <div className="space-y-8">
          {navigationMenu.map((item) => (
            <div
              onClick={() => handleNavigate(item)}
              className="flex items-center space-x-3 cursor-pointer"
            >
              {item.icon}
              <p className="text-xl">{item.title}</p>
            </div>
          ))}
        </div>
      </div>
      <div>
        <Divider />
        <div className="pl-5 flex items-center justify-between pt-5">
          <div className="flex items-center space-x-3">
            <Avatar src="https://cdn.pixabay.com/photo/2020/07/01/12/58/icon-5359553_960_720.png" />
            <div>
              <p className="font-bold">
                {auth.user?.firstName + " " + auth.user?.lastName}
              </p>
              <p className="opacity-70">{auth.user?.email}</p>
            </div>
          </div>
          <div>
            <Button
              id="basic-button"
              aria-controls={open ? "basic-menu" : undefined}
              aria-haspopup="true"
              aria-expanded={open ? "true" : undefined}
              onClick={handleClick}
            >
              <MoreVertIcon />
            </Button>
            <Menu
              id="basic-menu"
              anchorEl={anchorEl}
              open={open}
              onClose={handleClose}
              MenuListProps={{
                "aria-labelledby": "basic-button",
              }}
            >
              <MenuItem onClick={handleClose}>Profile</MenuItem>
              <MenuItem onClick={handleClose}>My account</MenuItem>
              <MenuItem onClick={handleClose}>Logout</MenuItem>
            </Menu>
          </div>
        </div>
      </div>
    </Card>
  );
};

export default Sidebar;
