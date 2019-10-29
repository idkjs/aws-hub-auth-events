open FormStyle;
module ButtonStyles = {
  open Css;
  let button =
    style([
      backgroundColor(`hex("#006bfc")),
      color(white),
      width(px(316)),
      height(px(45)),
      fontWeight(`num(600)),
      fontSize(px(14)),
      cursor(`pointer),
      borderStyle(`none),
      outlineStyle(`none),
      borderRadius(px(3)),
      marginTop(px(25)),
      boxShadow(
        Shadow.box(~x=px(0), ~y=px(1), ~blur=px(3), rgba(0, 0, 0, 0.3)),
      ),
    ]);
};
module FormErrors = {
  [@react.component]
  let make = (~formRules: FormTypes.formRules) =>
    <div>
      <ul>
        {Belt.Array.map(formRules, rule =>
           <li
             key={rule.id |> string_of_int}
             className={
               rule.valid
                 ? "is-success help is-size-6" : "is-danger help is-size-6"
             }>
             <i className={rule.valid ? "fas fa-check" : "fas fa-times"} />
             {" " |> React.string}
             {rule.message |> React.string}
           </li>
         )
         |> React.array}
      </ul>
    </div>;
};

[@react.component]
let make = (~formType, ~setUser=?) => {
  // let logger = () => Js.log("Form submitted");
  Js.log2("setUser", setUser);
  // let signUp = () => {
  //   FormTypes.
  //     // let (username, password, email,_)= formState;
  //     (
  //       Js.Promise.(
  //         Auth.signUp(
  //           ~username=state.username,
  //           ~password=state.password,
  //           ~email=state.email,
  //         )
  //         |> then_(_result => {
  //              Js.log("sign up success!");
  //              //  let formTypeToUpdate: FormTypes.formType = ConfirmSignUp;
  //              updateFormType(_ => ConfirmSignUp);
  //              resolve();
  //            })
  //         |> catch(err => {
  //              Js.log(err);
  //              let errMsg = "error signing up.." ++ Js.String.make(err);
  //              Js.log(errMsg);
  //              resolve();
  //            })
  //         |> ignore
  //       )
  //     );
  // };

  let (state, formRules, handleChange, handleSubmit, updateFormType) =
    UseForm.useForm(~formType: FormTypes.formType);

  /* async function signIn({ username, password }, setUser) {
       try {
         const user = await Auth.signIn(username, password)
         const userInfo = { username: user.username, ...user.attributes }
         setUser(userInfo)
       } catch (err) {
         console.log('error signing up..', err)
       }
     } */
  // let signIn = (~setUser) => {
  //   // let (username, password, email,_)= formState;
  //   Js.Promise.(
  //     Auth.signIn(~username=state.username, ~password=state.password)
  //     |> then_(user => {
  //          // let userInfo = { username: user##username, attributes:user##attributes}
  //          Js.log("sign up success!");
  //          Js.log(user);
  //          setUser(_ => user);
  //          //  let formTypeToUpdate: FormTypes.formType = SignUp;
  //          updateFormType(_ => SignUp);
  //          resolve();
  //        })
  //     |> catch(err => {
  //          Js.log(err);
  //          let errMsg = "error signing up.." ++ Js.String.make(err);
  //          Js.log(errMsg);
  //          resolve();
  //        })
  //     |> ignore
  //   );
  // };

  <div className=Styles.container>

      <div className="column is-4 is-offset-4">
        <h1 className="is-size-1 has-text-centered is-capitalized">
          {formType->FormTypes.formTypeToString |> React.string}
        </h1> // (A)
        <br />
        {switch (formRules) {
         | [||] => React.null
         | _ => <FormErrors formRules />
         }}
        <br />
        <div className="box">
          <form onSubmit=handleSubmit>
            {formType === SignUp
               // (C)
               ? <div className="field">
                   <label className="label">
                     {"Username" |> React.string}
                   </label>
                   <div className=Styles.input>
                     <input
                       className=Styles.input
                       type_="text"
                       name="username"
                       value={state.username}
                       required=true
                       onChange=handleChange // (D)
                     />
                   </div>
                 </div>
               : React.null}
            <div className="field">
              <label className="label">
                {"Email Address" |> React.string}
              </label>
              <div className="control">
                <input
                  className=Styles.input
                  type_="email"
                  name="email"
                  value={state.email}
                  required=true
                  onChange=handleChange
                />
              </div>
            </div>
            <div className="field">
              <label className="label"> {"Password" |> React.string} </label>
              <div className="control">
                <input
                  className=Styles.input
                  type_="password"
                  name="password"
                  value={state.password}
                  required=true
                  onChange=handleChange
                />
              </div>
            </div>
            <button type_="submit" className=ButtonStyles.button>
              {formType->FormTypes.formTypeToString |> React.string} // (A)
              <br />
            </button>
          </form>
        </div>
      </div>
    </div>;
    // <Button onClick={_=>signUp} title=formType />
};