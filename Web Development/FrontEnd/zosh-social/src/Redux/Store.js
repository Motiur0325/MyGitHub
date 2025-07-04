import { applyMiddleware, combineReducers, legacy_createStore } from "redux";
import { thunk } from "redux-thunk";
import { authReducer } from "./Auth/auth.reducer";
import { postReducer } from "./Auth/post.reducer";

const rootReducers=combineReducers({
auth:authReducer,
post:postReducer,
})

export const Store=legacy_createStore(rootReducers,applyMiddleware(thunk))