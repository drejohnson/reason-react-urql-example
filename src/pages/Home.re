open ReactHead;

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <Title> "Home Page"->Util.text </Title>
      <Meta name="description" content="It's a muthafuckin vibe bitch" />
      <section
        style={
          ReactDOMRe.Style.make(~padding="10px", ~fontFamily="Space Mono", ())
        }>
        <h1> "Home"->Util.text </h1>
        <QueryPosts />
      </section>
    </>,
};