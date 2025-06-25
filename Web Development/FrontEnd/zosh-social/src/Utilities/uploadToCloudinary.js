const cloud_name = "dpozpbddz";
const upload_preset = "zosh-social-youtube";

export const uploadToCloudinary = async (image, fileType) => {
  if (image && fileType) {
    console.log(image);
    console.log(fileType);
    const data = new FormData();
    data.append("file", image);
    data.append("upload_preset", upload_preset);
    data.append("cloud_name", cloud_name);
    const res = await fetch(
      `https://api.cloudinary.com/v1_1/${cloud_name}/${fileType}/upload`,
      { method: "post", body: data }
    );

    const fileData = await res.json();

    console.log("res", fileData.url);

    return fileData.url;
  } else {
    console.log(image);
    console.log(fileType);
    console.log("error........");
  }
};
