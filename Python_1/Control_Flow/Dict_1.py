user={'Dante':'active','Vergil':'active','Nero':'inactive'}
type(user)
print(user)
for u,status in user.copy().items():
    if status=='inactive':
        del user[u]
print(user)
