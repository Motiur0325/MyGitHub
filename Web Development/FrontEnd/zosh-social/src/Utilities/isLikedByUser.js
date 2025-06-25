export const isLikedByUser = (userId, post) => {
  for (let user of post.likes) {
    if (user.id === userId) {
      return true;
    }
  }
  return false;
};
