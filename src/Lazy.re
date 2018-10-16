module Home = {
  module Config = {
    module type t = (module type of Home);
  };

  module Loadable = ReLoadable.WithRender(Config);

  let make = _children =>
    Loadable.make(
      ~fetch=() => DynamicImport.import("./pages/Home.bs.js"),
      ~render=((module LazyComponent)) => <LazyComponent />,
      [||],
    );
};

module About = {
  module Config = {
    module type t = (module type of About);
  };

  module Loadable = ReLoadable.WithRender(Config);

  let make = _children =>
    Loadable.make(
      ~fetch=() => DynamicImport.import("./pages/About.bs.js"),
      ~render=((module LazyComponent)) => <LazyComponent />,
      [||],
    );
};

module NotFound = {
  module Config = {
    module type t = (module type of NotFound);
  };

  module Loadable = ReLoadable.WithRender(Config);

  let make = _children =>
    Loadable.make(
      ~fetch=() => DynamicImport.import("./pages/NotFound.bs.js"),
      ~render=((module LazyComponent)) => <LazyComponent />,
      [||],
    );
};