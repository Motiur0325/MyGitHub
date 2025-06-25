import { Button, TextField } from "@mui/material";
import { ErrorMessage, Field, Form, Formik } from "formik";
import React from "react";
import { useDispatch } from "react-redux";
// import * as Yup from "yup";
import { loginUserAction } from "../../Redux/Auth/auth.action";
import { useNavigate } from "react-router-dom";

const initialValues = { email: "", password: "" };
// const validationSchema={email:Yup.string().email("Invalid Email").required("Email is Required"),
//     password:Yup.string().min(6,"Should be at least of length 6").required("Password is Required"),
// };
const Login = () => {
  //   const [fromValue,setFormValue]=useState();
  const dispatch = useDispatch();

  const navigate = useNavigate();

  const handleSubmit = (values) => {
    dispatch(loginUserAction({ data: values }));
  };
  return (
    <>
      <Formik onSubmit={handleSubmit} initialValues={initialValues}>
        <Form className="space-y-5">
          <div className="space-y-5">
            <div>
              <Field
                as={TextField}
                name="email"
                placeholder="Email"
                type="email"
                variant="outlined"
                fullWidth
              />
            </div>

            <ErrorMessage
              name="email"
              component={"div"}
              className="text-red-500"
            />
          </div>

          <div className="space-y-5">
            <div>
              <Field
                as={TextField}
                name="password"
                placeholder="Password"
                type="password"
                variant="outlined"
                fullWidth
              />
            </div>

            <ErrorMessage
              name="password"
              component={"div"}
              className="text-red-500"
            />
          </div>
          <Button
            sx={{ padding: ".8rem 0rem" }}
            fullWidth
            type="submit"
            variant="contained"
            color="primary"
          >
            Log In
          </Button>
        </Form>
      </Formik>
      <div className="flex gap-2 pt-5 justify-center items-center">
        <p>Don't have any account ?</p>
        <Button onClick={() => navigate("/register")}>Register</Button>
      </div>
    </>
  );
};

export default Login;
