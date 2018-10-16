open ReactHead;

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <Meta name="description" content="It's a muthafuckin vibe" />
      <Layout>
        ...<Router.WithRouter>
             ...{
                  (~currentRoute) =>
                    switch (currentRoute) {
                    | Home => <Lazy.Home />
                    | About => <Lazy.About />
                    | _ => <Lazy.NotFound />
                    }
                }
           </Router.WithRouter>
      </Layout>
    </>,
};