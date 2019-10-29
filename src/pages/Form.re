open FormStyle;

let initialFormData: FormTypes.formState = {
  username: "",
  email: "",
  password: "",
  confirmationCode: "",
};

type formAction =
  | SetUsername(string)
  | SetEmail(string)
  | SetPassword(string)
  | SetConfirmationCode(string)
  | ResetState;

let formReducer = (state: FormTypes.formState, action: formAction) =>
  switch (action) {
  | SetUsername(username) => {...state, username}
  | SetEmail(email) => {...state, email}
  | SetPassword(password) => {...state, password}
  | SetConfirmationCode(confirmationCode) => {...state, confirmationCode}
  | ResetState => initialFormData
  };
[@react.component]
let make = (~formType, ~setUser: _ => unit) => {
  let (formType, updateFormType) = React.useState(() => formType);
  let valueFromEvent = (evt): string => evt->ReactEvent.Form.target##value;
  let nameFromEvent = (evt): string => evt->ReactEvent.Form.target##name;
  let (formData, dispatchFormData) =
    React.useReducer(formReducer, initialFormData);
  let signIn = () => {
    FormTypes.
      (
        Js.Promise.(
          Auth.signIn(
            ~username=formData.username,
            ~password=formData.password,
          )
          |> then_(data => {
               let userInfo = {
                 username: data##username,
                 attributes: data##attributes,
               };
               setUser(_ => Some(userInfo));
               Js.log(userInfo);
               ReasonReactRouter.push("/profile");
               Js.Promise.resolve(Belt.Result.Ok(userInfo));
             })
          |> catch(err => {
               let errMsg = "error signing up.." ++ Js.String.make(err);
               Js.log(errMsg);

               Js.Promise.resolve(Belt.Result.Error(errMsg));
             })
          |> ignore
        )
      );
  };
  let signUp = () => {
    let attributes: Js.Dict.t(Js.Json.t) =
      Js.Dict.fromList([
        ("email", Js.Json.string(formData.email)),
        // ("phone_number", Js.Json.string(phone_number)),
      ]);
    FormTypes.
      (
        Js.Promise.(
          Auth.signUp(
            ~username=formData.username,
            ~password=formData.password,
            ~attributes,
          )
          |> then_(data => {
               Js.log("sign up success!");
               updateFormType(_ => ConfirmSignUp);
               Js.Promise.resolve(Belt.Result.Ok(data));
             })
          |> catch(err => {
               let errMsg = "error signing up.." ++ Js.String.make(err);
               Js.log(errMsg);
               Js.Promise.resolve(Belt.Result.Error(errMsg));
             })
          |> ignore
        )
      );
  };
  let confirmSignUp = () => {
    FormTypes.
      (
        Js.Promise.(
          Auth.confirmSignUp(
            ~username=formData.username,
            ~confirmationCode=formData.confirmationCode,
          )
          |> then_(data => {
               Js.log("sign up confirmation success!");
               updateFormType(_ => SignIn);
               Js.Promise.resolve(Belt.Result.Ok(data));
             })
          |> catch(err => {
               let errMsg = "error signing up.." ++ Js.String.make(err);
               Js.log(errMsg);

               Js.Promise.resolve(Belt.Result.Error(errMsg));
             })
          |> ignore
        )
      );
  };
  let forgotPassword = () => {
    FormTypes.(
      Js.Promise.(
        Auth.forgotPassword(~username=formData.username)
        |> then_(data => {
             Js.log("forgotPasswordSubmit success!");
             updateFormType(_ => ForgotPasswordSubmit);
             Js.Promise.resolve(Belt.Result.Ok(data));
           })
        |> catch(err => {
             let errMsg =
               "forgotPasswordSubmit error.." ++ Js.String.make(err);
             Js.log(errMsg);

             Js.Promise.resolve(Belt.Result.Error(errMsg));
           })
        |> ignore
      )
    );
  };
  let forgotPasswordSubmit = () => {
    FormTypes.(
      Js.Promise.(
        Auth.forgotPasswordSubmit(
          ~username=formData.username,
          ~confirmationCode=formData.confirmationCode,
          ~password=formData.password,
        )
        |> then_(data => {
             Js.log("forgotPasswordSubmit success!");
             updateFormType(_ => SignIn);
             Js.Promise.resolve(Belt.Result.Ok(data));
           })
        |> catch(err => {
             let errMsg =
               "forgotPasswordSubmit error.." ++ Js.String.make(err);
             Js.log(errMsg);
             Js.Promise.resolve(Belt.Result.Error(errMsg));
           })
        |> ignore
      )
    );
  };

  let handleChange = evt => {
    ReactEvent.Form.persist(evt);
    let name = nameFromEvent(evt);
    let value = valueFromEvent(evt);

    switch (nameFromEvent(evt)) {
    | "username" => valueFromEvent(evt)->SetUsername |> dispatchFormData
    | "email" => valueFromEvent(evt)->SetEmail |> dispatchFormData
    | "password" => valueFromEvent(evt)->SetPassword |> dispatchFormData
    | "confirmationCode" =>
      valueFromEvent(evt)->SetConfirmationCode |> dispatchFormData
    | _ => ()
    };
  };
  let renderForm = () => {
    switch (formType) {
    | SignUp =>
      <SignUp onChange=handleChange formType onClick={_ => signUp()} />
    | SignIn =>
      <SignIn onChange=handleChange formType onClick={_ => signIn()} />
    | ConfirmSignUp =>
      <ConfirmSignUp
        onChange=handleChange
        formType
        onClick={_ => confirmSignUp()}
      />
    | ForgotPassword =>
      <ForgotPassword
        onChange=handleChange
        formType
        onClick={_ => forgotPassword()}
      />
    | ForgotPasswordSubmit =>
      <ForgotPasswordSubmit
        onChange=handleChange
        formType
        onClick={_ => forgotPasswordSubmit()}
      />
    };
  };
  <div>
      {renderForm()}
      {formType === SignUp
         ? <p className=Styles.toggleForm>
             "Already have an account? "->React.string
             <span
               className=Styles.anchor
               onClick={_ => updateFormType(_ => SignIn)}>
               "Sign In"->React.string
             </span>
           </p>
         : React.null}
      {formType === SignIn
         ? <>
             <p className=Styles.toggleForm>
               "Need an account? "->React.string
               <span
                 className=Styles.anchor
                 onClick={_ => updateFormType(_ => SignUp)}>
                 "Sign Up"->React.string
               </span>
             </p>
             <p
               className={Css.merge([
                 Styles.toggleForm,
                 Styles.resetPassword,
               ])}>
               "Forget your password? "->React.string
               <span
                 className=Styles.anchor
                 onClick={_ => updateFormType(_ => ForgotPassword)}>
                 "Reset Password"->React.string
               </span>
             </p>
           </>
         : React.null}
  </div>;
};