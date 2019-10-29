open FormTypes;
Js.log2("currentUserPoolUser", Auth.currentUserPoolUser);
let str = React.string;
// type formType = FormTypes.formType;
[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let current =
    switch (url.path) {
    | ["signin"] => "signin"
    | ["signup"] => "signup"
    | ["profile"] => "profile"
    | _ => "public"
    };
  // current;
  <>
    <Nav current />
    <main>
      <div className="task-container">
        {switch (url.path) {
         | ["signin"] => <Form formType=SignIn />
         | ["signup"] => <Form formType=SignUp />
         | ["profile"] => <Profile />
         | _ => <Public />
         }}
      </div>
    </main>
  </>;
};
let default = make;