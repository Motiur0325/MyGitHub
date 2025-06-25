import { Button, TextField } from "@mui/material";
import { ErrorMessage, Field, Form, Formik } from "formik";
import Radio from "@mui/material/Radio";
import RadioGroup from "@mui/material/RadioGroup";
import FormControlLabel from "@mui/material/FormControlLabel";
import React, { useState } from "react";
// import * as Yup from "yup";
import { useDispatch } from "react-redux";
import { registerUserAction } from "../../Redux/Auth/auth.action";
import { useNavigate } from "react-router-dom";

const initialValues = {
  firstName: "",
  lastName: "",
  email: "",
  password: "",
  gender: "",
};
// const validationSchema={email:Yup.string().email("Invalid Email").required("Email is Required"),
//     password:Yup.string().min(6,"Should be at least of length 6").required("Password is Required"),
// };
const Register = () => {
  const [gender, setGender] = useState("");
  const dispatch = useDispatch();
  const navigate = useNavigate();

  const handleSubmit = (values) => {
    values.gender = gender;
    dispatch(registerUserAction({ data: values }));
  };
  const handleChange = (event) => {
    setGender(event.target.value);
  };
  return (
    <>
      <Formik onSubmit={handleSubmit} initialValues={initialValues}>
        <Form className="space-y-5">
          <div className="space-y-5">
            <div>
              <Field
                as={TextField}
                name="firstName"
                placeholder="First Name"
                type="text"
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
                name="lastName"
                placeholder="Last Name"
                type="text"
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

          <RadioGroup
            row
            aria-label="gender"
            name="gender"
            onChange={handleChange}
          >
            <FormControlLabel
              value="female"
              control={<Radio />}
              label="Female"
            />
            <FormControlLabel value="male" control={<Radio />} label="Male" />
          </RadioGroup>

          <Button
            sx={{ padding: ".8rem 0rem" }}
            fullWidth
            type="submit"
            variant="contained"
            color="primary"
          >
            Register
          </Button>
        </Form>
      </Formik>
      <div className="flex gap-3 pt-5 justify-center items-center">
        <p>Already have an account ?</p>
        <Button onClick={() => navigate("/login")}>Log In</Button>
      </div>
    </>
  );
};

export default Register;
