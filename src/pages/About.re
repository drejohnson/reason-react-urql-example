open BsReactHead.ReactHead;

let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <Title> "About Page"->Util.text </Title>
      <Meta
        name="description"
        content="You think you know, but you don't know son"
      />
      <section
        style={
          ReactDOMRe.Style.make(~padding="10px", ~fontFamily="Space Mono", ())
        }>
        <h1> {"About" |> Util.text} </h1>
        <QueryPosts />
      </section>
    </>,
};