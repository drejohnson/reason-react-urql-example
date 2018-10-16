open ReasonUrql;

module GetPosts = [%graphql
  {|
    query getPosts {
      feed {
        id
        title
        content
      }
    }
  |}
];

let query = Query.query(GetPosts.make());

let component = ReasonReact.statelessComponent("QueryPosts");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <section>
        <Connect
          query
          render={
            (result: Connect.renderArgs(GetPosts.t, 'queryData, 'store)) =>
              switch (result##response) {
              | Loading => <div> "Loading"->Util.text </div>
              | Data(data) =>
                <div
                  style={
                    ReactDOMRe.Style.make(
                      ~display="grid",
                      ~gridTemplateColumns="1fr 1fr 1fr",
                      (),
                    )
                  }>
                  {
                    data##feed
                    ->Belt.Array.mapWithIndex((index, post) =>
                        <div
                          key={index |> string_of_int}
                          style={
                            ReactDOMRe.Style.make(
                              ~padding="10px",
                              ~fontFamily="Space Mono",
                              (),
                            )
                          }>
                          <img
                            style={
                              ReactDOMRe.Style.make(~maxHeight="200px", ())
                            }
                            src="https://via.placeholder.com/1280x720"
                            alt=post##title
                          />
                          <div
                            style={
                              ReactDOMRe.Style.make(
                                ~fontSize="20px",
                                ~fontWeight="700",
                                ~color="#222",
                                ~borderBottom="1px solid #222",
                                ~marginBottom="5px",
                                ~display="flex",
                                ~justifyContent="space-between",
                                (),
                              )
                            }>
                            <span> {post##title->Util.text} </span>
                          </div>
                          <div> {post##content->Util.text} </div>
                        </div>
                      )
                    ->ReasonReact.array
                  }
                </div>
              | Error(error) =>
                <div
                  style={
                    ReactDOMRe.Style.make(
                      ~display="flex",
                      ~padding="20px",
                      ~background="#f37fbf",
                      ~color="#900e56",
                      ~margin="20px",
                      ~fontFamily="Space Mono",
                      ~fontSize="20px",
                      (),
                    )
                  }>
                  {("Error: " ++ error##message)->Util.text}
                </div>
              }
          }
        />
      </section>
    </>,
};