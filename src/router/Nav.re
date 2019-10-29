open Antd;
open RouterLinks;

[@react.component]
let make = (~current) => {
  <div>
    <Menu selectedKeys=[|current|] mode=`horizontal>
      <Menu.Item key="home">
        <NavLink href="/"> <Icon icon=`home /> "Home"->React.string </NavLink>
      </Menu.Item>
      <Menu.Item key="profile">
        <NavLink href="/profile">
          <Icon icon=`profile />
          "Profile"->React.string
        </NavLink>
      </Menu.Item>
      <Menu.Item key="protected">
        <NavLink href="/protected">
          <Icon icon=`profile />
          "Protected"->React.string
        </NavLink>
      </Menu.Item>
    </Menu>
  </div>;
};