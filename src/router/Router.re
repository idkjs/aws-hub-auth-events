// open FormTypes;
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
         //  | ["signin"] => <div>  "formType=SignIn" ->React.string </div>
         //  | ["signup"] => <div>  "formType=SignUp" ->React.string </div>
         | [] => <Public />
         | ["profile"] => <Profile />
         | ["protected"] => <Protected />

         | _ => <Public />
         //  | ["profile"] => <Profile />
         //  | _ => <Public />
         }}
      </div>
    </main>
  </>;
};
let default = make;