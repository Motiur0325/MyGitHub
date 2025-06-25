import React from "react";

const SearchUser = () => {
  return (
    <div className="mt-3 mb-5">
      <input
        readOnly
        className="outline-none h-10 w-[100%] bg-slate-100 rounded-full px-5 bg-transparent border-[#3b4054] border"
        type="text"
        value="Search"
      />
    </div>
  );
};

export default SearchUser;
